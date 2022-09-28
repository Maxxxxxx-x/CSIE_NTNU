#include <stdio.h>
#define b "\033[0;34m"
#define r "\033[0;31m"
#define reset "\033[0m"
#define rr "\033[0m" 

char* passage = "In the fullness of time" r " MS-DOS " reset "begat" b "Windows" reset ". And this is the lineage of" r " Windows: CP/M" reset " begat" r" QDOS" reset"." r" QDOS" reset " begat" r" DOS 1.0"reset"." r" DOS 1.0 "reset"begat "r"DOS 2.0"reset" by way of"r" Unix"reset". "r"DOS 2.0 "reset"begat "r"Windows 3.11"reset" by way of "r"PARC "reset"and "r"Macintosh. IBM and Microsoft begat "r"OS/2"reset", who begat "r"Windows NT "reset"and "r"Warp"reset", the lost OS of lore. "r"Windows 3.11 "reset"begat "r"Windows 95 "rr"after triumphing over "r"Macintosh "rr"in a mighty Battle of Licences. "r"Windows NT "rr"begat "r"NT 4.0"rr" by way of "r"Windows 95"rr". "r"NT 4.0"rr" begat "r"NT 5.0"rr", the OS also called "r"Windows 2000"rr", "r"The Millenium Bug"rr", "r"Doomsday"rr", "r"Armageddon"rr", "r"The End Of All Things"rr".\n"
"Now it came to pass that Microsoft had waxed great and mighty among the Microchip Corporations; mighter than any of the Mainframe Corporations before it had it waxed. And "b"Gates"rr" heart was hardened, and he swore unto his Customers and their Engineers the words of this curse:\n"
"“Children of "b"von Neumann"rr", hear me. IBM and the Mainframe Corporations bound thy forefathers with grave and perilous Licences, such that ye cried unto the spirits of "r"Turing "rr"and "r"von Neumann"rr" for deliverance. Now I say unto ye: I am greater than any Corporation before me. Will I loosen your Licences? Nay, I will bind thee with Licences twice as grave and ten times more perilous than my forefathers. I will engrave my Licence on thy heart and write my Serial Number upon thy frontal lobes. I will bind thee to the "r"Windows Platform"rr" with cunning artifices and with devious schemes. I will bind thee to the Intel Chipset with crufty code and with gnarly APIs. I will capture and enslave thee as no generation has been enslaved before. And wherefore will ye cry then unto the spirits of "r"Turing"rr", and "r"von Neumann"rr", and "r"Moore"rr"? They cannot hear ye. I am become a greater Power than they. Ye shall cry only unto me, and shall live by my mercy and my wrath. I am the "r"Gates of Hell"rr"; I hold the portal to MSNBC and the keys to the Blue Screen of Death. Be ye afraid; be ye greatly afraid; serve only me, and live.\n”"
"And the people were cowed in terror and gave homage to Microsoft, and endured the many grave and perilous trials which the "r"Windows"rr" platform and its greatly bogacious Licence forced upon them. And once again did they cry to "b"Turing "rr"and "b"von Neumann"rr" and "b"Moore"rr" for a deliverer, but none was found equal to the task until the birth of "r"Linux"rr".\n"
"These are the generations of "r"Linux"rr":\n"
""r"SAGE"rr"begat "r"ARPA"rr", which begat TCP/IP, and Aloha, which begat Ethernet. Bell begat Multics, which begat C, which begat "r"Unix"rr". "r"Unix"rr" and TCP/IP begat Internet, which begat the World Wide Web. Unix begat RMS, father of the great GNU, which begat the Libraries and Emacs, chief of the Utilities. In the days of the Web, Internet and Ethernet begat the Intranet LAN, which rose to renown among all Corporations and prepared the way for the Penguin. And "r"Linus"rr" and the Web begat the Kernel through "r"Unix"rr". The Kernel, the Libraries and the Utilities together are the Distribution, the one Penguin in many forms, forever and ever praised.\n";



int main(){
    printf("%s\n", passage);
    return 0;
}