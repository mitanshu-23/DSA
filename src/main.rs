#![allow(dead_code, unused_variables, unused_imports)]

pub mod strings;

use std::vec;

pub mod arrays;

// use std::cell::RefCell;

pub mod binary_search;

fn main() {
    println!("Hello, world!");
    // println!("{}", binary_search::group_1::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![2, 5, 6, 0, 0, 1, 2], 3));
    // // [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
    // println!("{}", binary_search::group_1::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1], 2));
    // // [0, 0, 0, 1]
    // println!("{:?}", vec![0, 0, 0, 1]);
    // println!("{}", binary_search::group_1::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![0, 0, 0, 1], 1));
    // [1,0,1,1,1]
    // println!("{:?}", vec![1, 0, 1, 1, 1]);
    // println!("{}", binary_search::group_1::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 0, 1, 1, 1], 0));
    // [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
    // println!("{:?}", vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1]);
    // println!("{}", binary_search::group_1::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1], 2));
    // // arr=[1,0,1,1,1] target=0
    // println!("{:?}", vec![1, 0, 1, 1, 1]);
    // println!("{}", binary_search::group_1::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![1, 0, 1, 1, 1], 0));
    // [3,5,1]
    // println!("{:?}", vec![3, 5, 1]);
    // println!("{}", binary_search::group_1::medium::p09_search_in_rotated_sorted_array_ii_with_duplicates::Solution::search(vec![3, 5, 1], 1));
    // println!("{:?}", vec![19, 18, 11, 13, 15, 16, 17]);
    // println!("{}", binary_search::group_1::medium::p10_minimum_in_rotated_sorted_array::Solution::find_min(vec![18, 19, 11, 13, 15, 17]));
    // println!("{:?}", vec![4, 5, 6, 7, 0, 1, 2]);
    // println!("{}", binary_search::group_1::medium::p10_minimum_in_rotated_sorted_array::Solution::find_min(vec![4, 5, 6, 7, 0, 1, 2]));
    // println!("{:?}", vec![3, 4, 5, 1, 2]);
    // println!("{}", binary_search::group_1::medium::p10_minimum_in_rotated_sorted_array::Solution::find_min(vec![3, 4, 5, 1, 2]));

    // let nums = vec![2, 2, 3, 3, 7, 7, 10, 10, 11, 11, 12];
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_1::medium::p12_single_element_in_a_sorted_array::Solution::single_non_duplicate(nums));

    // let nums = vec![3, 3, 7, 7, 10, 10, 11, 11];
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_1::medium::p12_single_element_in_a_sorted_array::Solution::single_non_duplicate(nums));

    // let nums = vec![1, 1, 2];
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_1::medium::p12_single_element_in_a_sorted_array::Solution::single_non_duplicate(nums));

    // let nums = vec![1, 2, 1, -3, -5, -6, -7];
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_1::medium::p13_find_peak_element::Solution::find_peak_element(nums))

    // let num = 2147395599;
    // println!("{}", num);
    // println!("{}", binary_search::group_2::easy::p14_find_square_root_of_a_number_floor::Solution::my_sqrt(num));

    // let nums = vec![4, 7, 11];
    // let k = 4;
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_2::easy::p20_kth_missing_positive_number::Solution::find_kth_missing(nums, k));

    // let nums = vec![1, 2, 3, 4];
    // let k = 2;
    // println!("{:?}", nums);
    // println!("{}", binary_search::group_2::easy::p20_kth_missing_positive_number::Solution::find_kth_missing(nums, k));

    // Example 1:  bloomDay = [1,10,3,10,2],  m = 3,  k = 1  →  3
    // Example 2:  bloomDay = [1,10,3,10,2],  m = 3,  k = 2  →  -1
    // Example 3:  bloomDay = [7,7,7,7,12,7,7],  m = 2,  k = 3  →  12
    // let nums = vec![1, 10, 3, 10, 2];
    // let m = 3;
    // let k = 1;
    // println!("{}", binary_search::group_2::medium::p17_minimum_days_to_make_m_bouquets::Solution::min_days(nums, m, k));

    // let nums = vec![1, 10, 3, 10, 2];
    // let m = 3;
    // let k = 2;
    // println!("{}", binary_search::group_2::medium::p17_minimum_days_to_make_m_bouquets::Solution::min_days(nums, m, k));

    // let nums = vec![7, 7, 7, 7, 12, 7, 7];
    // let m = 2;
    // let k = 3;
    // println!("{}", binary_search::group_2::medium::p17_minimum_days_to_make_m_bouquets::Solution::min_days(nums, m, k));

    // Example 1:  nums = [1, 2, 5, 9],  threshold = 6   →  5
    //   (d=5: ceil(1/5)+ceil(2/5)+ceil(5/5)+ceil(9/5) = 1+1+1+2 = 5 <= 6)
    // Example 2:  nums = [44, 22, 33, 11, 1],  threshold = 5  →  44
    // let nums = vec![1, 2, 5, 9];
    // let threshold = 6;
    // println!("{}", binary_search::group_2::medium::p18_find_the_smallest_divisor_given_a_threshold::Solution::smallest_divisor(nums, threshold));

    // let nums = vec![44, 22, 33, 11, 1];
    // let threshold = 5;
    // println!("{}", binary_search::group_2::medium::p18_find_the_smallest_divisor_given_a_threshold::Solution::smallest_divisor(nums, threshold));

    // Example 1:  weights = [1,2,3,4,5,6,7,8,9,10],  days = 5  →  15
    // Example 2:  weights = [3,2,2,4,1,4],  days = 3  →  6
    // Example 3:  weights = [1,2,3,1,1],  days = 4   →  3

    // let weights = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];s

    // Example 1:  nums1 = [1, 3],  nums2 = [2]          →  2.0
    // Example 2:  nums1 = [1, 2],  nums2 = [3, 4]       →  2.5
    // 123344
    // let nums1 = vec![1, 2, 3, 4];
    // let nums2 = vec![3, 4];
    // // let threshold = 5;
    // println!("{}", binary_search::group_2::hard::p26_median_of_two_sorted_arrays::Solution::find_median_sorted_arrays(nums1, nums2));

    // let nums1 = vec![1];
    // let nums2 = vec![1];
    // println!("{}", binary_search::group_2::hard::p26_median_of_two_sorted_arrays::Solution::find_median_sorted_arrays(nums1, nums2));

    // let cell = RefCell::new(10);

    // let r1 = cell.borrow();
    // let r2 = cell.borrow();
    // println!("{} {}", r1, r2);

    // let mut w = cell.borrow_mut();
    // *w += 1;
    // println!("{}", w);

    // println!("{}", binary_search::group_2::hard::p26_median_of_two_sorted_arrays::Solution::find_median_sorted_arrays(nums1, nums2));

    // let nums = vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 60]];
    // println!("{}", binary_search::group_3::medium::p29_search_in_a_2d_matrix::Solution::search_matrix(nums, 60));

    // let matrix = vec![vec![1, 4], vec![3, 2]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![1, 5, 10, 5, 1], vec![6, 7, 8, 7, 6], vec![4, 3, 2, 1, 3]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![1, 4], vec![3, 2]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![10, 20, 15], vec![21, 30, 14], vec![7, 16, 32]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![10, 50, 40, 30, 20], vec![1, 500, 2, 3, 4]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![1, 5, 10, 5, 1], vec![6, 7, 8, 7, 6], vec![4, 3, 2, 1, 3]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![70, 50, 40, 30, 20], vec![100, 1, 2, 3, 4]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![7, 8, 9, 10, 11, 12, 13], vec![6, 5, 4, 3, 2, 1, 14]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let matrix = vec![vec![10, 20, 40, 50, 60, 70], vec![1, 4, 2, 3, 500, 80]];
    // println!("{:?}", binary_search::group_3::hard::p31_find_peak_element_in_2d_matrix::Solution::find_peak_grid(matrix));

    // let mut nums1 = vec![0, 0, 3, 0, 0, 0, 0, 0, 0];
    // let mut nums2 = vec![2, 5, 6, 7, 8, 9];

    // let n = nums2.len() as i32;
    // let m = nums1.len() as i32 - n;
    // arrays::group_02::hard::p35_merge_two_sorted_arrays_without_extra_space::Solution::merge_optimal(&mut nums1, m, &mut nums2, n);

    let nums = vec![1, 2, 2, 4];
    arrays::group_03::hard::p36_find_the_repeating_and_missing_number::Solution::find_missing_repeating(nums);

    // let nums =
}

// use std::io::{self, BufWriter, Read, Write};

// pub fn main() {
//     let mut input = String::new();
//     io::stdin().read_to_string(&mut input).unwrap();
//     let mut iter = input.split_ascii_whitespace();

//     macro_rules! next {
//         ($t:ty) => {
//             iter.next().unwrap().parse::<$t>().unwrap()
//         };
//     }

//     // let stdout = io::stdout();12  34
//     // let mut out = BufWriter::new(stdout.lock());
//     // println!("============================================ ");
//     let t = next!(u32);
//     // let t = 1;
//     for _ in 0..t {
//         // let n = next!(u32);
//         // solve2241C(x);
//         // let mut arr = Vec::new();
//         // for i in 0..n {
//         let b_str = next!(String);
//         // arr.push(k);
//         // }

//         solve1363B(&b_str)
//     }
// }

// fn solve1363B(b_str: &String) {
//     let mut pre_count: Vec<(i32, i32)> = Vec::new();
//     pre_count.push((0, 0));

//     for ch in b_str.chars() {
//         let last = pre_count.last();
//         if let Some(last) = last {
//             if ch == '0' {
//                 pre_count.push((last.0 + 1, last.1))
//             } else {
//                 pre_count.push((last.0, last.1 + 1));
//             }
//         }
//     }

//     let mut ans = b_str.len() as i32;
//     let mut indx = 0;
//     let b_str_bytes = b_str.as_bytes();

//     // println!("Pre Index: {:?}", pre_count);

//     while indx < b_str.len() {
//         let left_0 = pre_count[indx].0;
//         let left_1 = pre_count[indx].1;

//         let right_0 = pre_count[b_str.len()].0 - pre_count[indx + 1].0;
//         let right_1 = pre_count[b_str.len()].1 - pre_count[indx + 1].1;

//         let changes_01 = left_1 + right_0;
//         let changes_10 = left_0 + right_1;

//         // println!("{} {}", changes_01, changes_10);

//         ans = std::cmp::min(ans, std::cmp::min(changes_01, changes_10));

//         indx += 1;
//     }

//     println!("{}", ans);
// }

// 14
// 110
// 110011011110100111
// 10111101000010100
// 001111
// 0
// 00
// 0111000
// 1010111011110011011
// 11100100011101101
// 010100000111
// 1111101
// 000101100101111100
// 01001101000
// 0110

// struct Noisy(&'static str);

// impl Drop for Noisy {
//     fn drop(&mut self) {
//         println!("dropping {}", self.0);
//     }
// }

// fn main() {
//     let _a = Noisy("a");
//     let _b = Noisy("b");
//     println!("end of main");
// }
