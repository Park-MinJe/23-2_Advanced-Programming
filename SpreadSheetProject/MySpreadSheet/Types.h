#ifndef __TYPES_H__
#define __TYPES_H__

#ifndef __INCLUDE_IOSTREAM__
#define __INCLUDE_IOSTREAM__
#include <iostream>
#endif

#ifndef __INCLUDE_STRING__
#define __INCLUDE_STRING__
#include <string>
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace TypeCode {
	enum TypeCode {
		NOTDEFINED,

		NUMBER,
		INTEGER,
		DOUBLE,

		TEXT,

		DATETIME,
		DATE,
		TIME
	};
}
string TypeNames[] = {
	"NOTDEFINED",

	"NUMBER",
	"INTEGER",
	"DOUBLE",

	"TEXT",

	"DATETIME",
	"DATE",
	"TIME"
};

class Types {
	TypeCode::TypeCode typeCode;
	string typeName;
public:
	Types(TypeCode::TypeCode eTypeCode) : typeCode(eTypeCode), typeName(TypeNames[eTypeCode]) { }

	void setType(TypeCode::TypeCode eTypeCode) {
		typeCode = eTypeCode;
		typeName = TypeNames[eTypeCode];
	}
	
	TypeCode::TypeCode getTypeCode() {
		return typeCode;
	}
	string getTypeName() {
		return typeName;
	}
};

// Number
class Number : public Types {
	double value;

public:
	Number(TypeCode::TypeCode eTypeCode = TypeCode::NUMBER) : value(0), Types(eTypeCode) { }
	Number(double iV, TypeCode::TypeCode eTypeCode = TypeCode::NUMBER) : Types(eTypeCode), value(iV) { }

	void setValue(double dV) { value = dV; }
	double getValue() { return value; }
};

class Integer : public Number {
public:
	Integer() : Number(TypeCode::INTEGER) { }
	Integer(int iV) : Number((double)iV, TypeCode::INTEGER) { }
	
	void setIntValue(int iV) { setValue((double)iV); }
	int getIntValue() { return (int)getValue(); }
};

class Double : public Number {
public:
	Double() : Number(TypeCode::DOUBLE) { }
	Double(double iV) : Number(iV, TypeCode::DOUBLE) { }

	void setDoubleValue(double dV) { setValue(dV); }
	double getDoubleValue() { return getValue(); }
};

// Text
class Text : public Types {
	string text;

public:
	Text() :Types(TypeCode::TEXT) { }
	Text(string s) :Types(TypeCode::TEXT), text(s) { }

	void setText(string s) { text = s; }
	string getText() { return text; }
};

#ifndef __INCLUDE_CTIME__
#define __INCLUDE_CTIME__
#include <ctime>
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// DateTime
// Default Format : YYYY-MM-DD.HH:mm:ss
class DateTime : public Types {
	string dateTime;
public:
	DateTime() :Types(TypeCode::DATETIME) { }
	DateTime(string s) : Types(TypeCode::DATETIME), dateTime(s) { }
	DateTime(const time_t t) : Types(TypeCode::DATETIME) {
		struct tm tstruct;
		errno_t error = localtime_s(&tstruct, &t);

		char buf[80];
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
		dateTime = string(buf);
	}

	void setDateTime(string s) {
		dateTime = s;
	}
	void setDateTime(const time_t t) {
		struct tm tstruct;
		errno_t error = localtime_s(&tstruct, &t);

		char buf[80];
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
		dateTime = string(buf);
	}

	string getDateTime() { return dateTime; }
};

class Date : public DateTime {

};

class Time : public DateTime {

};

#endif