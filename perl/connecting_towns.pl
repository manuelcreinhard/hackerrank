my $tests = <>;
chomp $tests;
my $mod = 1234567;
for(my $i = 0; $i < $tests;$i++){
   my $towns = <>;
   my $line = <>;
   chomp $line;
   my @routes = split(" ",$line);
   my $res = 1;
   my $r_n = scalar @routes;
   for(my $j = 0;$j < $towns - 1;$j++){
      $res *= $routes[$j];
      $res = $res%$mod;
   }
   $n = $res%$mod;
   print "$n\n";
}
