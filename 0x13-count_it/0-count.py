#!/usr/bin/python3
"""Write a recursive function that queries the Reddit API, 
    parses the title of all hot articles, 
    and prints a sorted count of given keywords 
        (case-insensitive, delimited by spaces"""
import requests
from sys import argv


def count_words(subreddit, word_list, after="", counter={}, check=0):
    """does the thing"""
    if check == 0:
        for word in word_list:
            counter[word] = 0
    headers = {'User-Agent': 'steve'}
    json = requests.get('https://api.reddit.com/r/{}/hot?after={}'.
                        format(subreddit, after),
                        headers=headers).json()
    try:
        key = json['data']['after']
        parent = json['data']['children']
        for obj in parent:
            for word in counter:
                counter[word] += obj['data']['title'].lower().split(' ').count(
                    word.lower())
        if key:
            count_words(subreddit, word_list, key, counter, 1)
        else:
            res = sorted(counter.items(), key=lambda i: i[1], reverse=True)
            for key, value in res:
                if value != 0:
                    print('{}: {}'.format(key, value))
    except Exception:
        return None