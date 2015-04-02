$i=<>;
while($i--){
	$l=<>;
	$s=$l;$c=1;$j=4;$v=-1;
	while($j--){
		$v*=-1;
		$q=2+2*$j;
		$e=$l**$q;
		$s+=$e*$l*$v/f($q+1);
	    $c+=$e*$v/f($q);
	}
	print "$s\n$c\n";
}

sub f{
	return !$_[0]||$_[0]*f($_[0]-1);
}
