#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.n = 42;
	Data *pData = &data;
	co << data.n << nl;
	uintptr_t n = Serializer::serialize(pData);
	pData = Serializer::deserialize(n);
	co << data.n << nl;
	data.n = 123;
	co << data.n << nl;
	return (0);
}
