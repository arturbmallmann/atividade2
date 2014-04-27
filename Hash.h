#ifndef HASH_H_
#define HASH_H_
template <class Tipo>
class Hash{
	public:
		Hash();
		virtual ~Hash();
		int put(Tipo *dado);
		Tipo* get(const int chave);
	private:
};
#include "Hash.hpp"
#endif
