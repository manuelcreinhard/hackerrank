use Data::Dumper;
my $cases = <>;
my $str;
my %map_;
my $temp;
while($cases--){
	%map_ = ();
	$str = <>;
	chomp $str;
	for(my $i = 0; $i <= length $str; $i++){
		for(my $j = $i+1; $j <= length $str; $j++){
			$temp = substr($str,$i,$j-$i);
			$temp = join("",sort(split("",$temp)));
			
			if($map_{$temp}) {
				$map_{$temp}++;
			}  else {
				$map_{$temp} = 1;
			}
		}
	}
	my $count = 0;
	foreach my $key(keys %map_){

		if($map_{$key} > 0){
			#print Dumper $key;
			#print Dumper $map_{$key};
		}
			#print "key: $key\n";
			#print "temp: $temp\n";
		if($map_{$key} > 1){
			my $int = ($map_{$key}*($map_{$key}-1))/2;
			#print "int: $int\n";
			$count += $int;
		}
	}
	print "$count\n";
}
