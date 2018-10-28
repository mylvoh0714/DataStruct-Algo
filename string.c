vector<int> split(string s)
{
	vector<int> ret;

	int idx = 0;
	int val = 0;
	while ( s[idx] != ' ' )
	{
		val = 10 * val + ( s[idx] - '0' );
		idx++;
	}
	ret.push_back(val);
	val = 0;

	idx++;

	while ( idx < s.size() )
	{
		val = 10 * val + ( s[idx] - '0' );
		idx++;
	}
	ret.push_back(val);

	return ret;
}
