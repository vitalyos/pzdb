#include "PZDBController.h"

PZDBController::PZDBController(MongoService *service)
    : m_MongoService (service)
{
    m_MongoService->insert("temp", "1992", "Vitalyos Zsolt");
    qDebug () << m_MongoService->data("temp", "1992");
    m_MongoService->remove("temp", "1992");
    qDebug () << m_MongoService->data("temp", "1992");
}
