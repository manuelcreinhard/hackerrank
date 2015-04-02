use bignum;
my $cases = <>;
chomp $cases;
my @factorial = ();

for(my $i = 0; $i < $cases; $i++){
	my $line = <>;
	chomp $line;
	my @nm = split(" ", $line);
	$nm[1]--;
	if($nm[1] < 0){
		print "0\n";
		next;
	}
	my $u;
	my $d;
	if($nm[0] > $nm[1]){
		$u = getFactorialLimited($nm[0] + $nm[1],$nm[0]);
		$d = getFactorial($nm[1]);
	} else {
		$u = getFactorialLimited($nm[0] + $nm[1],$nm[1]);
		$d = getFactorial($nm[0]);
	}
	
	print "u: $u\n";
	print "d: $d\n";
	my $res = ($u / $d);
	#$res = $res%1000000007;
	print "$res\n";
	 
}

sub getFactorial{
	my $num = shift;
	if($num == 0){
		return 1;
	}
	if(defined($factorial[$num])){
		return $factorial[$num];
	}
	$res = $num * getFactorial($num - 1)%1000000007;
	$factorial[$num] = $res;
	return $res;
}

sub getFactorialLimited{
	my $num = shift;
	my $limit = shift;
	if($num == $limit){
		return 1;
	}
	return $num * getFactorialLimited($num - 1,$limit);
}
