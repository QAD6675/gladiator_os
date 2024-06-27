
long int atol(const char* nptr) {
	long int n = 0, neg = 0;
	while (*nptr) {
		if ((*nptr >= '0') && (*nptr <= '9')) {
			n = n * 10 + (*nptr - '0');
		} else if (*nptr == '-') {
			neg = 1;
		} else if (*nptr == '+') {
			neg = 0;
		}
		nptr++;
	}
	return neg ? -n : n;
}
