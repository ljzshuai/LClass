#ifndef LSINGTON_H
#define LSINGTON_H
namespace LJZ{

class LSington
{
public:
	~LSington();
	static LSington * getLSington();
	//add your code

private:
	//add your code

	LSington();
	class LSafetuClear
	{
	public:
		~LSafetuClear()
		{
			if (LSington::sington)
				delete LSington::sington;
		}
	};
	static LSington * sington;
	static LSafetuClear safetuClear;
};

}//end namespace LJZ
#endif // LSINGTON_H