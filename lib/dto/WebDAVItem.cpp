#include <QDateTime>
#include <QDebug>
#include <QString>
#include <QTextStream>

#include "../WebDAVClient.hpp"
#include "../utils/WebDAVReply.hpp"
#include "WebDAVItem.hpp"

WebDAVItem::WebDAVItem(WebDAVClient* webdavClient, QString href,
                       QString creationDate, QString lastModified,
                       QString displayName, QString contentType,
                       QString contentLength, bool isCollection) {
  this->webdavClient = webdavClient;
  this->href = href;
  this->creationDate =
      QDateTime::fromString(creationDate, Qt::DateFormat::ISODate);
  this->lastModified = lastModified;
  this->displayName = displayName;
  this->contentType = contentType;
  this->contentLength = contentLength.toInt();
  this->flagIsCollection = isCollection;

  //  qDebug() << href << creationDate << lastModified << displayName <<
  //  contentLength << contentType << isCollection;
}

bool WebDAVItem::isCollection() { return this->flagIsCollection; }

bool WebDAVItem::isFile() { return !this->flagIsCollection; }

WebDAVReply* WebDAVItem::download() {
  return this->webdavClient->downloadFrom(this->href);
}

void WebDAVItem::upload() {
  // TODO: Implement Functionality
}

WebDAVReply* WebDAVItem::listDir() {
  return this->webdavClient->listDir(this->href);
}

QString WebDAVItem::toString() {
  QString s;
  QTextStream out(&s);

  out << "HREF            : " << this->href << "," << endl
      << "CREATION_DATE   : " << this->creationDate.toString() << "," << endl
      << "LAST_MODIFIED   : " << this->lastModified << "," << endl
      << "DISPLAY_NAME    : " << this->displayName << "," << endl
      << "CONTENT_TYPE    : " << this->contentType << "," << endl
      << "CONTENT_LENGTH  : " << this->contentLength << "," << endl
      << "IS_COLLECTION   : " << this->flagIsCollection;

  return s;
}

QString WebDAVItem::getHref() { return this->href; }

QDateTime WebDAVItem::getCreationDate() { return this->creationDate; }

QString WebDAVItem::getLastModified() { return this->lastModified; }

QString WebDAVItem::getDisplayName() { return this->displayName; }

QString WebDAVItem::getContentType() { return this->contentType; }

int WebDAVItem::getContentLength() { return this->contentLength; }

WebDAVItem WebDAVItem::fromHref() {
  // TODO: Implement Functionality
}
