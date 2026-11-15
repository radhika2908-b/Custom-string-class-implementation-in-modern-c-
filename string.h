#include<iostream>
using namespace std;
class String
{
        char *p;
        public:
        String()                       //default
        {
                p=new char[1];
		p[0]='\0';
        }
        String(const char * s)         //paramitrazed
        {
		int len=0,i=0;
		while(s[len])
			len++;

                p=new char[len+1];
		for(int i = 0; s[i]; i++)
           		 p[i] = s[i];
		p[len]='\0';
        }
        String(const String &obj)     //copy
        {
		int len=0;
		while(obj.p[len])
			len++;
                p=new char[len+1];
		for(int i = 0; obj.p[i]; i++)
           		 p[i] = obj.p[i];
		p[len]='\0';
        }
        String& operator=(const String &obj)//assignment
        {
 	     if(this == &obj)
        	return *this;
	    delete []p;

       	   int len = strlen(obj);
	    p = new char[len + 1];

    		for(int i = 0; obj.p[i]; i++)
        		p[i] = obj.p[i];

	    p[len] = '\0';
   	 return *this;
        }
        String operator+(const String);
        char& operator[](int);
        int operator<(const String&);
        int operator>(const String);
        int operator<=(const String);
        int operator>=(const String);
        int operator==(const String);
        int operator!=(const String);
        ~String()
	{
                delete []p;
        }
        friend istream& operator>>(istream& in,String&);
        friend ostream& operator<<(ostream& out,const String&);
        friend char * strcpy(String&,const String&);
        friend char * strncpy(String&,const String&,int);
        friend int strcmp(const String&,const String&);
        friend int strncmp(const String&,const String&,size_t);
        friend char * strcat(String&,const String&);
        friend char * strncat(String&,const String&,size_t);
        friend int strlen(const String&);
        friend char *strrev(String&);
        friend char *strupr(String&);
        friend char *strlwr(String&);
        friend char *strchr(String&,char);
        friend char *strrchr(String&,char);
        friend char *strstr(String&,String&);

};
/*int main()
{
	String s1("abvd"),s2;
	char *p;
	cin>>s2;
	if(p=strstr(s1,s2))
		cout<<p<<endl;
}*/
char * strstr(String& s,String& p)
{
	int i,j,k;
	if(p.p[0]=='\0')
		return s.p;
	for(i=0;s.p[i];i++)
	{
		for(j=i,k=0;p.p[k];k++,j++)
			if(s.p[j]!=p.p[k])
				break;
		if(p.p[k]=='\0')
			return s.p+i;
	}
	return 0;
}
char *strchr(String& s,char ch)
{
	int i=0;
	while(s.p[i])
	{
		if(s.p[i]==ch)
			return s.p+i;
		i++;
	}
	return 0;
}
char *strrchr(String& s,char ch)
{
	int i=0,st=-1;
	while(s.p[i])
	{
		if(s.p[i]==ch)
			st=i;
		i++;
	}
	if(st!=-1)
		return s.p+st;
	else
		return 0;
}
char *strupr(String& s)
{
        int i=0;
        while(s.p[i])
        {
                if(s.p[i]>='a'&&s.p[i]<='z')
                        s.p[i]=s.p[i]-32;
                i++;
        }
        return s.p;
}
char *strlwr(String& s)
{
	int i=0;
        while(s.p[i])
        {
                if(s.p[i]>='A'&&s.p[i]<='Z')
                        s.p[i]=s.p[i]+32;
                i++;
        }
        return s.p;
}
char *strrev(String& s)
{
        int len= strlen(s)-1,i=0;
        while(i<len)
        {
                char ch=s.p[i];
                s.p[i++]=s.p[len];
                s.p[len--]=ch;
        }
        return s.p;
}
int strlen(const String& s)
{
    int i = 0;
    while(s.p[i])
        i++;
    return i;
}
char * strcat(String& d,const String& s)
{
	int len1=strlen(d),len2=strlen(s);
	char *temp=new char[len1+len2+1];
	int i=0;
	while(d.p[i])
	{
		temp[i]=d.p[i];
		i++;
	}
	int j=0;
	while(s.p[j])
	{
		temp[i]=s.p[j];
		i++,j++;
	}
	temp[i]='\0';
	String te(temp);
	delete []temp;
	d=te;
	return d.p;
}
char * strncat(String& d,const String& s,size_t n)
{
	int len1=strlen(d),len2=strlen(s);
	char *temp=new char[len1+n+1];
	int i=0;
	while(d.p[i])
	{
		temp[i]=d.p[i];
		i++;
	}
	int j=0;
	while(s.p[j] && j < n)
	{
		temp[i]=s.p[j];
		i++,j++;
	}
	temp[i]='\0';
	String te(temp);
	delete []temp;
	d=te;
	return d.p;
}
int strcmp(const String& d, const String& s)
{
    const char *dp = d.p;
    const char *sp = s.p;
    for(; *dp || *sp; dp++, sp++)
        if(*dp != *sp)
            return (*dp - *sp);
    return 0;
}
int strncmp(const String& d, const String& s, size_t n)
{
    int i=0;
    const char *dp = d.p;
    const char *sp = s.p;
    for(; (*dp || *sp)&&(i<n); dp++, sp++,i++)
        if(*dp != *sp)
            return (*dp - *sp);
    return 0;
}
char * strcpy(String &d,const String &s)
{
        int i=0,len=strlen(s);
	delete []d.p;
	d.p=new char[len+1];
        while(s.p[i])
                d.p[i++]=s.p[i];
        d.p[i]='\0';
        return d.p;
}
char * strncpy(String &d,const String &s,int n)
{
        int i=0,len=strlen(s);
	delete []d.p;
	if(n>len)
		n=len;
	d.p=new char[n+1];
        while(s.p[i]&&i<n)
                d.p[i++]=s.p[i];
        d.p[i]='\0';
        return d.p;
}
int String::operator>(String obj)
{
        int n=strcmp(*this,obj);
        if(n>0)
                return 1;
        return 0;
}
int String::operator<=(String obj)
{
        int n=strcmp(*this,obj);
        if(n<=0)
                return 1;
        return 0;
}
int String::operator>=(String obj)
{
        int n=strcmp(*this,obj);
        if(n>=0)
                return 1;
        return 0;
}
int String::operator==(String obj)
{
        int n=strcmp(*this,obj);
        if(n==0)
                return 1;
        return 0;
}
int String::operator!=(String obj)
{
        int n=strcmp(*this,obj);
        if(n!=0)
                return 1;
        return 0;
}
int String::operator<(const String& obj)
{
        int n=strcmp(*this,obj);
        if(n<0)
                return 1;
        return 0;
}
char& String::operator[](int i)
{
        return p[i];
}
String String::operator+(const String obj)
{   
    int len1 = strlen(obj);
    int len2 = strlen(*this);
    char *temp = new char[len1 + len2 + 1];
    int i = 0;
    while(this->p[i])
    {
        temp[i] = this->p[i];
        i++;
    }

    int j = 0;
    while(obj.p[j])
    {
        temp[i] = obj.p[j];
        i++;
        j++;
    }

    temp[i] = '\0';
    String te(temp);
    delete []temp;
    return te;
}
istream& operator>>(istream& in,String &obj)
{
	int i=0,k=1000;
	char ch=-1,*temp=new char [k];
	while(1)
	{
		in.get(ch);
		if(ch==' '||ch=='\n')
			break;
		temp[i]=ch;
		i++;
		if(i==k)
		{
			k=k+1000;
			char *temp1=new char[k];
			for(int p=0;p<=i;p++)
				temp1[p]=temp[p];
			delete []temp;
			temp=new char[k];
			for(int p=0;p<=i;p++)
				temp[p]=temp1[p];
			delete []temp1;
		}
	}
	temp[i]='\0';
	delete []obj.p;
	obj.p=new char[i+1];
	for(i=0;temp[i];i++)
		obj.p[i]=temp[i];
	obj.p[i]='\0';
	delete []temp;
        return in;
}
ostream& operator<<(ostream& out,const String &obj)
{
        out<<obj.p;
        return out;
}
