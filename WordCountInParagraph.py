if __name__ == '__main__':
    try:
        paragraph = input('Enter long string paragraph:')
        set_of_words = set(paragraph.split(" "))
        no_of_occurance_dict = {key:paragraph.count(key) for key in set_of_words}
        print(no_of_occurance_dict)
    except Exception as e:
        print(e)