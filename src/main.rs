#![allow(dead_code, unused_variables, unused_imports)]

pub mod binary_search;

fn main() {
    println!("Hello, world!");
    // println!("{}", binary_search::group_1_1d_arrays::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![2, 5, 6, 0, 0, 1, 2], 3));
    // // [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
    // println!("{}", binary_search::group_1_1d_arrays::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1], 2));
    // // [0, 0, 0, 1]
    // println!("{:?}", vec![0, 0, 0, 1]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![0, 0, 0, 1], 1));
    // [1,0,1,1,1]
    // println!("{:?}", vec![1, 0, 1, 1, 1]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 0, 1, 1, 1], 0));
    // [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
    // println!("{:?}", vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1], 2));
    // // arr=[1,0,1,1,1] target=0
    // println!("{:?}", vec![1, 0, 1, 1, 1]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 0, 1, 1, 1], 0));
    // [3,5,1]
    // println!("{:?}", vec![3, 5, 1]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![3, 5, 1], 1));
    // println!("{:?}", vec![19, 18, 11, 13, 15, 16, 17]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p10_minimum_in_rotated_sorted_array::Solution::find_min(vec![18, 19, 11, 13, 15, 17]));
    // println!("{:?}", vec![4, 5, 6, 7, 0, 1, 2]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p10_minimum_in_rotated_sorted_array::Solution::find_min(vec![4, 5, 6, 7, 0, 1, 2]));
    // println!("{:?}", vec![3, 4, 5, 1, 2]);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p10_minimum_in_rotated_sorted_array::Solution::find_min(vec![3, 4, 5, 1, 2]));

    let nums = vec![2, 2, 3, 3, 7, 7, 10, 10, 11, 11, 12];
    println!("{:?}", nums);
    println!("{}", binary_search::group_1_1d_arrays::medium::p12_single_element_in_a_sorted_array::Solution::single_non_duplicate(nums));

    // let nums = vec![3, 3, 7, 7, 10, 10, 11, 11];
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p12_single_element_in_a_sorted_array::Solution::single_non_duplicate(nums));

    // let nums = vec![1, 1, 2];
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_1_1d_arrays::medium::p12_single_element_in_a_sorted_array::Solution::single_non_duplicate(nums));
}
