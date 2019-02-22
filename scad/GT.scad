module	GTlogo() {
	linear_extrude(height=5) {
		union() {
			polygon(points=[
				[10,14],
				[4,14],
				[0,10],
				[0,4],
				[4,0],
				[10,0],
				[12,2],
				[12,0],
				[14,0],
				[14,8],
				[8,8],
				[8,6],
				[12,6],
				[12,4],
				[10,2],
				[4,2],
				[2,4],
				[2,10],
				[4,12],
				[10,12] ]);
			polygon(points=[
				[18,0],
				[18,12],
				[12,12],
				[12,14],
				[20,14],
				[20,0] ]);
			polygon(points=[
				[22,14],
				[26,14],
				[26,12],
				[22,12] ]);
		}
	}
}
gtlogo_w = 26;
gtlogo_l = 14;
gtlogo_h = 5;