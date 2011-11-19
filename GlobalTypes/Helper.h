#include <ctype.h>

class Helper {
	public:
		int getLength(const char* array) {
			int length;
			for(length = 0; array[length] != '\0'; length++);
			return length;
		}

		static void copy(char* destination, const char* source, int length) {
			for(int i = 0; i < length; i++) {
				destination[i] = source[i];
			}
		}

		static bool compare(const char* first, const char* second) {
			int i;
			for(i = 0; first[i] != '\0' && second[i] != '\0'; i++) {
				if (first[i] != second[i]) return false;
			}
			if (first[i] != second[i]) return false;
			return true;
		}

		static bool compare(const char* first, const char* second, int length) {
			for(int i = 0; i < length; i++) {
				if (first[i] != second[i]) return false;
			}
			return true;
		}

		static bool compareCaseInsensitive(const char* first, const char* second) {
			int i;
			for(i = 0; first[i] != '\0' && second[i] != '\0'; i++) {
				if (tolower(first[i]) != tolower(second[i])) return false;
			}
			if (tolower(first[i]) != tolower(second[i])) return false;
			return true;
		}

		static bool compareCaseInsensitive(const char* first, const char* second, int length) {
			for(int i = 0; i < length; i++) {
				if (tolower(first[i]) != tolower(second[i])) return false;
			}
			return true;
		}
};
