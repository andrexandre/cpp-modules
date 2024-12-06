#include "RPN.hpp"

bool hasInvalidDigit(char c)
{
	return !std::isdigit(c) &&
	c != '+' && c != '-' && c != '*' && c != '/' && c != ' ';
}

bool parsingError(STR str)
{
	if (std::find_if(str.begin(), str.end(), hasInvalidDigit)
	!= str.end())
		return 1;
	int charCounter = 0,
		digitCounter = 0,
		operationCounter = 0;
	std::stringstream ss(str);
	while (ss >> str)https://www.google.com/search?sca_esv=360d606574466e04&biw=1920&bih=911&sxsrf=ADLYWIL6vMurwBTBFxUVRY2XvpMAGkxUqA:1733497646236&q=Jacobsthal+numbers&source=lnms&fbs=AEQNm0Aa4sjWe7Rqy32pFwRj0UkWd8nbOJfsBGGB5IQQO6L3JyJJclJuzBPl12qJyPx7ESI3cvVcqCdLSFFSD0xy83Mxw5VfItgi7r_Cn7smOncBUAR5RxAPnHf8VakeHGZjYFl6tkX8aXn-STnDnC7kirxfPzyvwuy6yG0ppW8USwHesglRN-Y&sa=X&ved=2ahUKEwix1rD7tZOKAxWMT6QEHc0qGNoQ0pQJegQIEBAB
	{
		if (str[1])
			return 1;
		if (isdigit(str[0]))
			digitCounter++;
		else if (str[0] != ' ')
			operationCounter++;
		charCounter++;
		if (digitCounter <= operationCounter)
			return 1;
	}
	if (charCounter < 3 || digitCounter != operationCounter + 1)
		return 1;
	return 0;
}

void execution(STR input)
{
	std::stringstream ss(input);
	std::stack<int> st;
	while (ss >> input)
	{
		if (isdigit(input[0]))
			st.push(input[0] - '0');
		else
		{
			int snd = st.top(); st.pop();
			int fst = st.top(); st.pop();
			int res = -1;
			// co << fst << " " << input[0] << " " << snd << nl;
			switch (input[0])
			{
			case '+':
				res = fst + snd;
				break;
			case '-':
				res = fst - snd;
				break;
			case '*':
				res = fst * snd;
				break;
			case '/':
				if (snd != 0)
					res = fst / snd;
				else
				{
					co << "undefined ඞ" << nl;
					return;
				}
			}
			st.push(res);
		}
	}
	co << st.top() << nl;
}

int main(int ac, char **av)
{
	if (ac != 2 || parsingError(av[1]))
		return (co << "Error" << nl), 0;
	execution(av[1]);
	return (0);
}
