class CHAIR {
public:
	void* BACK;
	void* SEAT;
	void* LEGS;
	void* ARMS;
protected:
	int NUMLEGS;
private:
	void* TEXTURE;
	void* ROUGHNESS;
};

class DESK {
public:
	void* LEGS;
protected:
	int NUMLEGS;

private:
	void* TEXTURE;
	void* ROUGHNESS;
};
