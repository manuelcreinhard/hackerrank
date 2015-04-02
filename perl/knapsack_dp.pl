use List::Util 'max';
my $loops = <>;
my @list;
my $t_weight;
my @objects = ();
chomp $loops;
for(my $i = 0;$i<$loops;$i++){
	my $input = <>;
	chomp $input;
	$t_weight = substr($input,index($input," ")+1);
	my $lst = <>;
	chomp $lst;
	@list = split(" ",$lst);
	@objects = ();
	my $result = knapsack($t_weight);
	print "$result\n";
}

sub knapsack{
	my $w = shift;
	return $objects[$w] if ($objects[$w]);
	return 0 if $w <= 0;
	my $temp = 0;
	$objects[$w] = 0;
	foreach my $element (@list){
		$temp = knapsack($w - $element) + $element if(($w -$element) >= 0);
		$objects[$w] = $temp if($temp > $objects[$w]);
	}
	return $objects[$w];
}
