my $cases = <>;
chomp $cases;
my $count = 0;
for(my $i = 0; $i < $cases;$i++){
	my $line = <>;
	chomp $line;
	if($line =~ /hackerrank/i){
		$count++;
	}
}
print "$count\n";
