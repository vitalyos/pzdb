#ifndef PZDBCONTROLLER_H
#define PZDBCONTROLLER_H

#include "MongoService.h"

class PZDBController
{
public:
    PZDBController(MongoService * service);
private:
    MongoService * m_MongoService;
};

#endif // PZDBCONTROLLER_H
