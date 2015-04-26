#ifndef __IREFCOUNTED_H
#define __IREFCOUNTED_H

class IRefcounted {
public:
	IRefcounted() {}

	virtual int AddRef() = 0;
	virtual int RemoveRef() = 0;

protected:
	virtual ~IRefcounted() {}
};

#endif
