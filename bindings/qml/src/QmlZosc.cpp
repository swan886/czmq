/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "QmlZosc.h"


///
//  Return chunk data size
size_t QmlZosc::size () {
    return zosc_size (self);
};

///
//  Return OSC chunk data. Caller does not own the data!
byte *QmlZosc::data () {
    return zosc_data (self);
};

///
//  Return the OSC address string
const QString QmlZosc::address () {
    return QString (zosc_address (self));
};

///
//  Return the OSC format of the message.
//    i - 32bit integer
//    h - 64bit integer
//    f - 32bit floating point number (IEEE)
//    d - 64bit (double) floating point number
//    s - string (NULL terminated)
//    t = timetag: an OSC timetag in NTP format (uint64_t)
//    S - symbol
//    c - char
//    m - 4 byte midi packet (8 digits hexadecimal)
//    T - TRUE (no value required)
//    F - FALSE (no value required)
//    N - NIL (no value required)
//    I - Impulse (for triggers) or INFINITUM (no value required)
//    b - binary blob
const QString QmlZosc::format () {
    return QString (zosc_format (self));
};

///
//  Append data to the osc message. The format describes the data that
//  needs to be appended in the message. This essentially relocates all
//  data!
//  The format type tags are as follows:
//    i - 32bit integer
//    h - 64bit integer
//    f - 32bit floating point number (IEEE)
//    d - 64bit (double) floating point number
//    s - string (NULL terminated)
//    t = timetag: an OSC timetag in NTP format (uint64_t)
//    S - symbol
//    c - char
//    m - 4 byte midi packet (8 digits hexadecimal)
//    T - TRUE (no value required)
//    F - FALSE (no value required)
//    N - NIL (no value required)
//    I - Impulse (for triggers) or INFINITUM (no value required)
//    b - binary blob
int QmlZosc::append (const QString &format) {
    return zosc_append (self, format.toUtf8().data());
};

///
//  Retrieve the values provided by the given format. Note that zosc_retr
//  creates the objects and the caller must destroy them when finished.
//  The supplied pointers do not need to be initialized. Returns 0 if
//  successful, or -1 if it failed to retrieve a value in which case the
//  pointers are not modified. If an argument pointer is NULL is skips the
//  value. See the format method for a detailed list op type tags for the
//  format string.
int QmlZosc::retr (const QString &format) {
    return zosc_retr (self, format.toUtf8().data());
};

///
//  Create copy of the message, as new chunk object. Returns a fresh zosc_t
//  object, or null if there was not enough heap memory. If chunk is null,
//  returns null.
QmlZosc *QmlZosc::dup () {
    QmlZosc *retQ_ = new QmlZosc ();
    retQ_->self = zosc_dup (self);
    return retQ_;
};

///
//  Transform zosc into a zframe that can be sent in a message.
QmlZframe *QmlZosc::pack () {
    QmlZframe *retQ_ = new QmlZframe ();
    retQ_->self = zosc_pack (self);
    return retQ_;
};

///
//  Return a string describing the the OSC message. The returned string must be freed by the caller.
QString QmlZosc::dump () {
    char *retStr_ = zosc_dump (self);
    QString retQStr_ = QString (retStr_);
    free (retStr_);
    return retQStr_;
};

///
//  Dump OSC message to stdout, for debugging and tracing.
void QmlZosc::print () {
    zosc_print (self);
};

///
//  Return a pointer to the item at the head of the OSC data.
//  Sets the given char argument to the type tag of the data.
//  If the message is empty, returns NULL and the sets the
//  given char to NULL.
const void *QmlZosc::first (char *type) {
    return zosc_first (self, type);
};

///
//  Return the next item of the OSC message. If the list is empty, returns
//  NULL. To move to the start of the OSC message call zosc_first ().
const void *QmlZosc::next (char *type) {
    return zosc_next (self, type);
};

///
//  Return a pointer to the item at the tail of the OSC message.
//  Sets the given char argument to the type tag of the data. If
//  the message is empty, returns NULL.
const void *QmlZosc::last (char *type) {
    return zosc_last (self, type);
};

///
//  Set the provided 32 bit integer from value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
int QmlZosc::popInt32 (int *val) {
    return zosc_pop_int32 (self, val);
};

///
//  Set the provided 64 bit integer from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
int QmlZosc::popInt64 (int64_t *val) {
    return zosc_pop_int64 (self, val);
};

///
//  Set the provided float from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
int QmlZosc::popFloat (float *val) {
    return zosc_pop_float (self, val);
};

///
//  Set the provided double from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
int QmlZosc::popDouble (double *val) {
    return zosc_pop_double (self, val);
};

///
//  Set the provided string from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success. Caller owns the string!
int QmlZosc::popString (QString val) {
    return zosc_pop_string (self, val.toUtf8().data());
};

///
//  Set the provided char from the value at the current cursor position in the message.
//  If the type tag at the current position does not correspond it will fail and
//  return -1. Returns 0 on success.
int QmlZosc::popChar (char *val) {
    return zosc_pop_char (self, val);
};

///
//  Set the provided boolean from the type tag in the message. Booleans are not represented
//  in the data in the message, only in the type tag. If the type tag at the current
//  position does not correspond it will fail and return -1. Returns 0 on success.
int QmlZosc::popBool (bool *val) {
    return zosc_pop_bool (self, val);
};

///
//  Set the provided 4 bytes (unsigned 32bit int) from the value at the current
//  cursor position in the message. If the type tag at the current position does
//  not correspond it will fail and return -1. Returns 0 on success.
int QmlZosc::popMidi (uint32_t *val) {
    return zosc_pop_midi (self, val);
};


QObject* QmlZosc::qmlAttachedProperties(QObject* object) {
    return new QmlZoscAttached(object);
}


///
//  Transform zosc into a zframe that can be sent in a message.
//  Take ownership of the chunk.
QmlZframe *QmlZoscAttached::packx (QmlZosc *selfP) {
    QmlZframe *retQ_ = new QmlZframe ();
    retQ_->self = zosc_packx (&selfP->self);
    return retQ_;
};

///
//  Transform a zframe into a zosc.
QmlZosc *QmlZoscAttached::unpack (QmlZframe *frame) {
    QmlZosc *retQ_ = new QmlZosc ();
    retQ_->self = zosc_unpack (frame->self);
    return retQ_;
};

///
//  Probe the supplied object, and report if it looks like a zosc_t.
bool QmlZoscAttached::is (void *self) {
    return zosc_is (self);
};

///
//  Self test of this class.
void QmlZoscAttached::test (bool verbose) {
    zosc_test (verbose);
};

///
//  Create a new empty OSC message with the specified address string.
QmlZosc *QmlZoscAttached::construct (const QString &address) {
    QmlZosc *qmlSelf = new QmlZosc ();
    qmlSelf->self = zosc_new (address.toUtf8().data());
    return qmlSelf;
};

///
//  Create a new OSC message from the specified zframe. Takes ownership of
//  the zframe.
QmlZosc *QmlZoscAttached::fromframe (QmlZframe *frame) {
    QmlZosc *qmlSelf = new QmlZosc ();
    qmlSelf->self = zosc_fromframe (frame->self);
    return qmlSelf;
};

///
//  Create a new zosc message from memory. Take ownership of the memory
//  and calling free on the data after construction.
QmlZosc *QmlZoscAttached::frommem (char *data, size_t size) {
    QmlZosc *qmlSelf = new QmlZosc ();
    qmlSelf->self = zosc_frommem (data, size);
    return qmlSelf;
};

///
//  Create a new zosc message from a string. This the same syntax as
//  zosc_create but written as a single line string.
QmlZosc *QmlZoscAttached::fromstring (const QString &oscstring) {
    QmlZosc *qmlSelf = new QmlZosc ();
    qmlSelf->self = zosc_fromstring (oscstring.toUtf8().data());
    return qmlSelf;
};

///
//  Create a new zosc message from the given format and arguments.
//  The format type tags are as follows:
//    i - 32bit integer
//    h - 64bit integer
//    f - 32bit floating point number (IEEE)
//    d - 64bit (double) floating point number
//    s - string (NULL terminated)
//    t = timetag: an OSC timetag in NTP format (uint64_t)
//    S - symbol
//    c - char
//    m - 4 byte midi packet (8 digits hexadecimal)
//    T - TRUE (no value required)
//    F - FALSE (no value required)
//    N - NIL (no value required)
//    I - Impulse (for triggers) or INFINITUM (no value required)
//    b - binary blob
QmlZosc *QmlZoscAttached::create (const QString &address, const QString &format) {
    QmlZosc *qmlSelf = new QmlZosc ();
    qmlSelf->self = zosc_create (address.toUtf8().data(), format.toUtf8().data());
    return qmlSelf;
};

///
//  Destroy an OSC message
void QmlZoscAttached::destruct (QmlZosc *qmlSelf) {
    zosc_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
