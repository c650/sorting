#! /usr/bin/env ruby
require_relative "./sorting.rb"

def pa(arr)
	print "#{arr}\n"
end

arr = []
10.times do |x|
	arr << rand(0...10)
end

pa(arr)
pa(arr.sort)

arr.shuffle!
Sorting.bubblesort(arr)
pa(arr)

arr.shuffle!
Sorting.insertionsort(arr)
pa(arr)

arr.shuffle!
Sorting.selectionsort(arr)
pa(arr)

arr.shuffle!
Sorting.mergesort(arr)
pa(arr)

arr.shuffle!
Sorting.quicksort(arr)
pa(arr)
