// 打开网页.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<Windows.h>
#include<atlstr.h>
#include<string>
using namespace std;


int main()
{
	wstring code; // 股票代码
	wstring start; // 开始时间
	wstring end; // 结束时间
	cout << "请输入股票代码，数据开始时间和数据结束时间：";
	wcin >> code >> start >> end;
	int flag;
	cout << "是否是深圳股票（1-是，0-不是）：";
	cin >> flag;
	if (flag == 1)
	{
		code = L'1' + code;
	}
	else
	{
		code = L'0' + code;
	}
	CString URL;
	URL.Format(L"http://quotes.money.163.com/service/chddata.html?code=%s&start=%s&end=%s&fields=TCLOSE;HIGH;LOW;TOPEN;LCLOSE;CHG;PCHG;TURNOVER;VOTURNOVER;VATURNOVER;TCAP;MCAP",
		code.c_str(), start.c_str(), end.c_str());
	ShellExecute(NULL, L"open", URL, NULL, NULL, SW_SHOWNORMAL);
	/*CString URL = L"http://quotes.money.163.com/service/chddata.html?code=1000001&start=20170101&end=20190720&fields=TCLOSE;HIGH;LOW;TOPEN;LCLOSE;CHG;PCHG;TURNOVER;VOTURNOVER;VATURNOVER;TCAP;MCAP";
	ShellExecute(NULL, L"open", URL, NULL, NULL, SW_SHOWNORMAL);*/
}

