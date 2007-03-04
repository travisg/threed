#ifndef __IREFCOUNTED_H
#define __IREFCOUNTED_H

class IRefcounted {
public:
	IRefcounted() {}
	virtual ~IRefcounted() {}

	virtual int AddRef() = 0;
	virtual int RemoveRef() = 0;
};

#endif
