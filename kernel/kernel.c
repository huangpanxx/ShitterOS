#include "interrupt.h"
#include "print.h"

int main() {
	put_str(36,2,10,"Fuck YOU");
	setup_idt();
	put_str(36,2,10,"Fuck YOU2");
	return 0;
}

