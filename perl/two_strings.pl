my $cases = <>;
my $a, my $b;
while($cases--){
	$a = <>;
	$b = <>;
	chomp $a;
	chomp $b;
	$a =~ s/(\w)\1/$1/g;
	$b =~ s/(\w)\1/$1/g;
	my %a_, my %b_;
	$a_{$_}++ for (split("",$a));
	$b_{$_}++ for (split("",$b));
	my $match = 0;
	foreach my $key (keys %a_) {
		if($b_{$key}){
			print "YES\n";
			$match = 1;
			last;
		}
	}
	if(!$match){
		print "NO\n";
	}
}
