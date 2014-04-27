template <class Tipo>
class Hash{
	public:
		Hash();
		virtual ~Hash();
		int put(Tipo dado);
		Tipo get(int chave);
	private:
};
