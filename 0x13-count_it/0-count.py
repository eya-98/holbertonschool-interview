#!/usr/bin/python3
""" a recursive function that queries the Reddit API, """
import requests


def count_words(subreddit, wordsList, dictionary={}, after=""):
    """prints a sorted count of given keywords"""
    if len(dictionary) <= 0:
        for item in wordsList:
            dictionary[item] = 0
    if after is None:
        wordsList = [[key, value] for key, value in dictionary.items()]
        wordsList = sorted(wordsList, key=lambda x: (-x[1], x[0]))
        for key in wordsList:
            if key[1]:
                print("{}: {}".format(key[0].lower(), key[1]))
        return None
    url = "https://api.reddit.com/r/{}/hot".format(subreddit)
    request = requests.get(
        url,
        headers={
            'user-agent': 'my-app/0.0.1'},
        params={
            'limit': 100,
            'after': after})
    if request.status_code != 200:
        return None
    json = request.json()
    data = json.get("data")
    after = data.get("after")
    children = data.get("children")
    for child in children:
        data = child.get("data")
        titles = data.get("title")
        TitleLower = [title.lower() for title in titles.split(' ')]
        for key in wordsList:
            dictionary[key] += TitleLower.count(key.lower())
    count_words(subreddit, wordsList, dictionary, after)
