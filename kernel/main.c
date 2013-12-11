void put_chr(int x,int y,int chr);
void put_str(const char* str);

int main() {
	put_str("Fuck YOU");
	return 0;
}

void put_str(const char* str) {
	int x;
	for(x=0;str[x]!=0;++x) {
		int s = ((0x2+x)<<8) + str[x];
		put_chr(x,0,s);
	}
}
