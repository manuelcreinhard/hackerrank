
my $a = <>;
my $b = <>;
chomp $a;
chomp $b;
my @a_ = split("",$a);
my @b_ = split("",$b);
my %map_;
%map_ = map {$_ => $map_->{$_}++} @a_;
%map_ = (%map_,map {$_ => $map_->{$_}--} @b_);
my $count = 0;
foreach my $key (keys %map_){
	$count += abs($map_->{$key});
}

print "$count\n";
