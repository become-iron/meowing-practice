export function bubbleSort(array: Array<string | number>): Array<string | number> {
  // eslint-disable-next-line no-constant-condition
  while (true) {
    let sorted = true

    for (let i = 0; i < array.length - 1; i++) {
      if (array[i] > array[i + 1]) {
        sorted = false
        ;[array[i], array[i + 1]] = [array[i + 1], array[i]]
      }
    }

    if (sorted) {
      return array
    }
  }
}

export function bubbleSortOptimized(array: Array<string | number>): Array<string | number> {
  for (let i = 0; i < array.length; i++) {
    let sorted = true

    for (let j = 0; j < array.length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        sorted = false
        ;[array[j], array[j + 1]] = [array[j + 1], array[j]]
      }
    }

    if (sorted) {
      return array
    }
  }

  return array
}

console.log(bubbleSort([1, 3, -1, 100, 14, 32]))
console.log(bubbleSort(['23', 'sdf', '123', '3ds']))
console.log(bubbleSortOptimized([1, 3, -1, 100, 14, 32]))
console.log(bubbleSortOptimized([2, 1, 3, 4, 6, 5]))
console.log(bubbleSortOptimized(['23', 'sdf', '123', '3ds']))
