module Sorting
	def self.bubblesort(arr)
		c = true
		while c
			c = false
			for j in 0...(arr.length-1)
				if arr[j] > arr[j+1]
					arr[j],arr[j+1] = arr[j+1],arr[j]
					c = true
				end # end if
			end # end for
		end # end for
	end

	def self.insertionsort(arr)
		arr.length.times do |x|

			for i in 1...arr.length

				if arr[i-1] > arr[i]
					hold = arr[i]
					pos = i

					while pos > 0 && arr[pos - 1] > hold
						arr[pos] = arr[pos - 1]
						pos -= 1
					end # end while
					arr[pos] = hold
				end # end if
			end # end for
		end	# end .times
	end # end def

	def self.selectionsort(arr)
		for i in 0...arr.length

			min_pos = i
			for j in i+1...arr.length
				min_pos = j if arr[j] < arr[min_pos]
			end # end for

			arr[min_pos], arr[i] = arr[i], arr[min_pos]
		end # end for
	end

	def self.mergesort(arr)
		return arr if arr.length <= 1
		if arr.length == 2
			arr[0],arr[1] = arr[1],arr[0] if arr[0] > arr[1]
			return arr
		end

		left = mergesort(arr[0...arr.length/2].dup)
		right = mergesort(arr[arr.length/2...arr.length].dup)

		i = 0
		until left.empty? || right.empty?
			arr[i] = (left.first < right.first ? left.shift : right.shift)
			i+=1
		end

		if !left.empty?
			i.upto(arr.length-1){|j| arr[j] = left.shift }
		elsif !right.empty?
			i.upto(arr.length-1){|j| arr[j] = right.shift }
		end

		return arr
	end

	def self._quicksort(arr, _begin, _end)
		return if _end - _begin <= 1

		a = _begin
		b = _end - 1

		pivot = arr[ b ]

		while (b > a)
			if arr[b-1] > pivot
				arr[b] = arr[b-1]
				b-=1
			else
				arr[b-1],arr[a] = arr[a],arr[b-1]
				a+=1
			end
		end

		arr[b] = pivot

		self._quicksort(arr, _begin, b)
		self._quicksort(arr, b+1, _end)
	end

	def self.quicksort(arr)
		self._quicksort(arr, 0, arr.length)
	end
end
