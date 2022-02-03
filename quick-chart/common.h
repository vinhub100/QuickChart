
#include <QStringList>
#include <QJsonObject>
#include <QClipboard>

extern QStringList rList;
extern QStringList fList;
extern QJsonObject chartobject;


extern int saveRecent(QString charcter);
extern int loadRecent(void);
extern int saveFavourite(void);
extern int loadFavourite(void);


extern int saveStore(QString storeType);
extern int loadStore(QString storeType);

extern QClipboard *cb;
