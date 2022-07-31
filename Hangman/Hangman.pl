#!/usr/local/bin/perl

use strict;
use warnings;
use experimental 'switch';
use Array::Utils qw(:all);




    my $string = "computer|radio|calculator|teacher|bureau|police|geometry|president|subject|country
    |enviroment|classroom|animals|province|month|politics|puzzle|instrument|kitchen|language
    |vampire|ghost|solution|service|software|virus25|security|phonenumber|expert|website
    |agreement|support|compatibility|advanced|search|triathlon|immediately|encyclopedia
    |endurance|distance|nature|history|organization|international|championship|government
    |popularity|thousand|feature|wetsuit|fitness|legendary|variation|equal|approximately|segment
    |priority|physics|branche|science|mathematics|lightning|dispersion|accelerator|detector
    |terminology|design|operation|foundation|application|prediction|reference|measurement
    |concept|perspective|overview|position|airplane|symmetry|dimension|toxic|algebra|illustration
    |classic|verification|citation|unusual|resource|analysis|license|comedy|screenplay
    |production|release|emphasis|director|trademark|vehicle|aircraft|experiment"; 

    my @list = split( '\|', $string);
    my $word = $list[rand @list];
    my $dashes = length($word);

    print "Guess the word: ";
    for (my $i=0; $i < $dashes; $i++)
    {print "_ ";}

    my @pick = split( '|', $word);
    
    my $x = -1;
    my @guess;
    my @misses;

    START:

    my $win = scalar array_minus (@pick,@guess);
    if ($win == 0)
    {
        print ("\n\nYOU WON THE GAME!!\n\n");
        goto EXIT;
    }

    $x=$x+1;
    print "\n\nType any letter between a and z: ";
    
        $guess[$x] = <STDIN>;
  
        chomp $guess[$x];
           
  
    for ( my $j=0; $j < $dashes ; $j++ )
        {
            my $found = 0;
            foreach my $guess_one (@guess)  
            {   
                if ($guess_one eq $pick[$j])
                { $found = 1; }
            }                    
                if($found)
                { print $pick[$j] ;
                print" ";}
                else
                {print "_ ";}      
        }       
    

  
    my $miss = 1;
    for (my $r=0; $r < $dashes; $r++)
    {   
         $miss = 0 if $guess[$x] eq $pick[$r];   
    }
    
        if ($miss)
        { push(@misses,$guess[$x]);}

    print "\n\n Misses: ";
    print join (", ", @misses);
    my $errors = scalar @misses; 

    given($errors)
    {
        when('1')
        {
            print("\n\nYou have 4 chances left!
                      _____ 
                     |     | 
                     |     |
                     |     | 
                     |      
                     |     
                     |      
                   __|__");
            goto START;  
            
        }
        when('2') 
        { 
            print("\n\nYou have 3 chances left!
                      _____ 
                     |     | 
                     |     |
                     |     | 
                     |     O 
                     |      
                     |      
                   __|__");
            goto START;    
        }
        when('3') 
        {
            print("\n\nYou have 2 chances left!
                      _____ 
                     |     |  
                     |     | 
                     |     |  
                     |     O 
                     |     |  
                     |       
                   __|__");
            goto START; 
            
        }
        when('4') 
        {
            print("\n\nYou have only 1 chance left!!
                      _____ 
                     |     |  
                     |     | 
                     |     |  
                     |     O 
                     |    /|\\  
                     |       
                   __|__");
            goto START;    
        }
        when('5')
        {
            print"\n\n YOU LOST!!
                      _____  
                     |     |  
                     |     | 
                     |     |  
                     |     O  
                     |    /|\\  
                     |    / \\ 
                   __|__
                \n  GAME OVER\n\n";
        }
        default 
        {
            print"\n You have 5 chances left\n";
            goto START;
        }
    }
    EXIT:
    exit();
    

    
