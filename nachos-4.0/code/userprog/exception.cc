// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "main.h"
#include "syscall.h"
#include "machine.h"
#include "addrspace.h"

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

void
ExceptionHandler(ExceptionType which)
{
	int	type = kernel->machine->ReadRegister(2);
	int	val;

	// add for project3
	if ( which ==  PageFaultException ) {
		kernel->stats->numPageFaults++; // page fault
		// cout << "Raise PageFaultException \n";

		int victim;		// find the page victim
		val = kernel->machine->ReadRegister(BadVAddrReg); // The failing virtual address on an exception

		DEBUG(dbgAddr, "Bad Virtual Address: " << val);

		int vpn = (unsigned) val / PageSize;
    	int offset = (unsigned) val % PageSize;

		char *buffer1;
		char *buffer2;
		buffer1 = new char[PageSize];
		buffer2 = new char[PageSize];

		// Random
		victim = ( rand() % NumPhysPages );

		// perform page replacement, write victim frame to disk, read desired frame to memory
		/// take out the value of victim
		bcopy( &kernel->machine->mainMemory[victim*PageSize], buffer1, PageSize );
		kernel->synchDisk->ReadSector( kernel->machine->pageTable[vpn].virtualPage, buffer2 );	
		/// write the value into memory
		bcopy( buffer2, &kernel->machine->mainMemory[victim*PageSize], PageSize );		
		kernel->synchDisk->WriteSector( kernel->machine->pageTable[vpn].virtualPage, buffer1 );	// write the swap

		// update page status
		kernel->machine->pageTable[AddrSpace::RevePhyPages[victim]].valid = false;
		kernel->machine->pageTable[AddrSpace::RevePhyPages[victim]].virtualPage = kernel->machine->pageTable[vpn].virtualPage;

		kernel->machine->pageTable[vpn].valid = true;
		kernel->machine->pageTable[vpn].physicalPage = victim;
		
		AddrSpace::RevePhyPages[victim] = vpn;

		return;
	}
	

    switch (which) {
	case SyscallException:
	    switch(type) {
		case SC_Halt:
		    DEBUG(dbgAddr, "Shutdown, initiated by user program.\n");
   		    kernel->interrupt->Halt();
		    break;
		case SC_PrintInt:
			val=kernel->machine->ReadRegister(4);
			cout << "Print integer:" <<val << endl;
			return;
		case SC_Sleep:
			val=kernel->machine->ReadRegister(4);
			// cout << "Sleep Time in (ms): " << val << endl;
			kernel->alarm->WaitUntil( val );
			return;
/*		case SC_Exec:
			DEBUG(dbgAddr, "Exec\n");
			val = kernel->machine->ReadRegister(4);
			kernel->StringCopy(tmpStr, retVal, 1024);
			cout << "Exec: " << val << endl;
			val = kernel->Exec(val);
			kernel->machine->WriteRegister(2, val);
			return;
*/		case SC_Exit:
			DEBUG(dbgAddr, "Program exit\n");
			val=kernel->machine->ReadRegister(4);
			cout << "return value:" << val << endl;
			delete kernel->currentThread->space;
			kernel->currentThread->Finish();
			break;
		default:
		    cerr << "Unexpected system call " << type << "\n";
 		    break;
	    }
	    break;
	case AddressErrorException:
		cout << "Raise AddressErrorException \n";
		break;
	default:
	    cerr << "Unexpected user mode exception " << which << "\n";
	    break;
    }
    ASSERTNOTREACHED();
}
