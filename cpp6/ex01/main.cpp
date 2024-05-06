#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.n = 42;
	Data *pData = &data;
	Data *sData = NULL;
	co << data.n << nl;
	uintptr_t n = Serializer::serialize(pData);
	sData = Serializer::deserialize(n);
	if (pData == sData)
		co << "The return of deserialize() == the original pointer." << nl;
	co << data.n << nl;
	data.n = 123;
	co << data.n << nl;
	return (0);
}
