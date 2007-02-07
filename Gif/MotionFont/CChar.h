
#include <vector>
using namespace std;
class CChar
{
	unsigned int data;
	CChar(char* p, bool dchar);
	void Init(char* p, bool dchar);
public:
	CChar(char* p);
	static void from(char* p, vector<CChar>& chars);
	const char* c_str();
	int length();
};