// alarm.cc
//	Routines to use a hardware timer device to provide a
//	software alarm clock.  For now, we just provide time-slicing.
//
//	Not completely implemented.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "alarm.h"
#include "main.h"

//----------------------------------------------------------------------
// Alarm::Alarm
//      Initialize a software alarm clock.  Start up a timer device
//
//      "doRandom" -- if true, arrange for the hardware interrupts to 
//		occur at random, instead of fixed, intervals.
//----------------------------------------------------------------------

Alarm::Alarm(bool doRandom)
{
    timer = new Timer(doRandom, this);
}

//----------------------------------------------------------------------
// Alarm::CallBack
//	Software interrupt handler for the timer device. The timer device is
//	set up to interrupt the CPU periodically (once every TimerTicks).
//	This routine is called each time there is a timer interrupt,
//	with interrupts disabled.
//
//	Note that instead of calling Yield() directly (which would
//	suspend the interrupt handler, not the interrupted thread
//	which is what we wanted to context switch), we set a flag
//	so that once the interrupt handler is done, it will appear as 
//	if the interrupted thread called Yield at the point it is 
//	was interrupted.
//
//	For now, just provide time-slicing.  Only need to time slice 
//      if we're currently running something (in other words, not idle).
//	Also, to keep from looping forever, we check if there's
//	nothing on the ready list, and there are no other pending
//	interrupts.  In this case, we can safely halt.
//----------------------------------------------------------------------

void 
Alarm::CallBack() 
{
    Interrupt *interrupt = kernel->interrupt;
    MachineStatus status = interrupt->getStatus();
    bool wakeup = sleeplist.ToReady();
    
    if (status == IdleMode && !wakeup && sleeplist.IsEmpty()) {	// is it time to quit?
        if (!interrupt->AnyFutureInterrupts()) {
	    timer->Disable();	// turn off the timer
	}
    } else {			// there's someone to preempt
	interrupt->YieldOnReturn();
    }
}

// Project 2 Add
void Alarm::WaitUntil( int x ) {
    // close interrupt
    IntStatus oldLevel = kernel->interrupt->SetLevel(IntOff);
    Thread *t = kernel->currentThread;
    cout << "Alarm::WaitUntil: go to sleep." << endl;
    sleeplist.ToSleep(t, x);
    // open interrupt
    kernel->interrupt->SetLevel( oldLevel );
}

bool Sleep_list::IsEmpty() {
    return Sleep_thread_list.size() == 0;
}

void Sleep_list::ToSleep( Thread *t, int x) {
    ASSERT( kernel->interrupt->getLevel() == IntOff );
    Sleep_thread_list.push_back( Sleep_thread(t, interrupt_count + x) );
    t->Sleep(false);
}

bool Sleep_list::ToReady() {
    bool wakeup = false;
    interrupt_count++;
    for ( list<Sleep_thread>::iterator it = Sleep_thread_list.begin(); it != Sleep_thread_list.end(); it++ ) {
        if (interrupt_count >= it->sleep_time ) {
            wakeup = true;
            cout << "Sleep_list::ToReady, a thread wake up." << endl;
            kernel->scheduler->ReadyToRun( it->thread_sleep );
            it = Sleep_thread_list.erase( it );
        }                                                                               
    }
    return wakeup;
}