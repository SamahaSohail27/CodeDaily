# Counting Sort
- If the range of the input data is very small compared to the number of input data.
- Array
  - 3,4,4,2,3,2,4,1,3,1,2,3
- Count Array
  - 0 2 3 4 3
# Important points to consider:
- Counting sort demonstrates optimal performance when sorting integers within a range smaller than the quantity of items to be sorted.
- This sorting method is characterized by stability, a lack of comparisons, and a non-recursive nature.
- A prerequisite for its application is the awareness of the input range.
- Counting sort is commonly employed as a subroutine within other sorting algorithms, such as radix sort.
- Owing to a partial hashing mechanism, Counting sort efficiently counts occurrences of data objects in O(1) time.
- Its adaptability extends to sorting negative input values.
- Is Counting sort categorized as an in-place algorithm?
    - No, it certainly doesn't qualify as an "in-place" sorting algorithm since it utilizes additional space equivalent to the original array.
