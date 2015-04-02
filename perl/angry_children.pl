# Enter your code here. Read input from STDIN. Print output to STDOUT
my $lines = <>;
my $window_size = <>;
my @list = ();
for(my $i = 0;$i < $lines;$i++){
   my $a = <>;
   chomp $a;
   $a += 0;
   push @list,$a;
}
@list = sort { $a <=> $b } @list;
my $min = $list[$window_size -1] - $list[0];
my @window = @list[0..$window_size - 1];
for(my $i = 1; $i < $lines - $window_size + 1; $i++){
	$temp_min = $list[$i+$window_size-1] - $list[$i];
   if($temp_min < $min){
	   $min = $temp_min;
	   @window = @list[$i..$i+$window_size - 1];
   }
}
print "$min\n";
