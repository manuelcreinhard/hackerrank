my $val=<>;
chomp $val;
my $size=<>;
chomp $size;
my $line=<>;
chomp $line;
my @arr = split(" ",$line);
my $count = 0;
foreach my $element(@arr){
	last if ($element == $val);
	$count++;
}
print "$count\n";
