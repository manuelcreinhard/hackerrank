use Data::Dumper;
%map = ();
sub substrings {
	my $str = shift;
	my %submap;
	for(my $i = 0; $i < length $str; $i++){
		for(my $j = $i+1; $j <= length $str; $j++){
			$submap{substr($str,$i,$j-$i)} = 1;
		}
	}
	return \%submap;
}


sub substringsDyn {
	my $str = shift;
	#print "Searching substrings for: $str\n";
	return if length $str == 0;
	return if $map{$str};
	if (length $str == 1){
		#print "Adding: $str\n";
		$map{$str} = 1;
		return;
	}
	my $left = substr($str,0,(length $str) -1);
	my $right = substr($str,1,length $str);
	$map{$str} = 1;
	if(!$map{$left}){
		#$map{$left} = 1;
		#print "Adding: $left\n";
		substringsDyn($left);
	}
	if(!$map{$right}){
		#$map{$right} = 1;
		#print "Adding: $right\n";
		substringsDyn($right);
	}
}

my $cases = <>;
while($cases--){
	my $str = <>;
	chomp $str;
	#print Dumper "Starting substr search";
	substringsDyn($str);
	#print Dumper "Finished substr search";
	my @v = keys %map;
	@v = sort @v;
	my $k = <>;
	my $concat = join("",@v);
	#print "$concat\n";
	my $c = substr($concat,$k-1,1);
	print "$c\n";
}

