vector <vector <int> > bwd(2);
	for(int i = 0; i < 2; i++)bwd[i].resize(n + 10);

	bwd[0][0] = INT_MIN;
	bwd[1][0] = a[0];	
	for(int i = 1; i <= n; i++) {
		bwd[0][i] = max(bwd[0][i - 1], bwd[1][i - 1]);
		bwd[1][i] = bwd[1][i - 1] - a[i - 1] + b[i - 1] + a[i];
	}