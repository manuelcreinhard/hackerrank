my @fib = (1,1);

sub fibo {
	my $i = shift;
	return $fib[$i] if $fib[$i];
	$fib[$i] = fibo($i-1) + fibo($i-2);
	return $fib[$i];
}

my $cases = <>;
while($cases--){
	my $num = <>;
	my $last = scalar @fib;
	$last--;
	while($num > $fib[$last]){
		fibo($last + 1);
		$last++;
	}
	my $found = 0;
	for(my $i = scalar @fib - 1; $i > 0; $i--){
		last if $num > $fib[$i];
		if($num == $fib[$i]){
			$found = 1;
			last;
		}
	}
	if($found){
		print "IsFibo\n";
	} else {
		print "IsNotFibo\n";
	}
}
