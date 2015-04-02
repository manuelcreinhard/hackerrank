$a=<>;
while($a--){
	$b=<>;
	$r=0;
	while($b--){
		$r+=(1-2*($b%2))/(2*$b+1);
	}
	print "$r\n";
}
