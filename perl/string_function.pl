use Data::Dumper;

sub substrings {
	my $str = shift;
	my %submap;
	for(my $i = 0; $i < length $str; $i++){
		for(my $j = $i+1; $j <= length $str; $j++){
			$submap{substr($str,$i,$j-$i)}++
		}
	}
	return \%submap;
}

my $word = <>;
chomp $word;
my $map = substrings($word);
my $max = 0;
my $temp;
for my $key (keys %{$map}){
	$temp = (length $key) * $map->{$key};
	if($temp > $max){
		$max = $temp;
	}
}

print "$max\n";
