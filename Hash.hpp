#ifndef HASH_HPP
#define HASH_HPP
template <class Tipo>
class Hash{
	public:
		Hash();
		virtual ~Hash();
		int put(Tipo &dado);
		Tipo* get(const int chave);
	private:
};
#endif
