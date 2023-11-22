from queue import Queue 
def fifo(pages, n, capacity): 
	s = set() 
	indexes = Queue() 
	page_faults = 0
	for i in range(n): 
		if (len(s) < capacity): 
			if (pages[i] not in s): 
				s.add(pages[i]) 
				page_faults += 1
				indexes.put(pages[i])  
		else: 
			if (pages[i] not in s): 
				val = indexes.queue[0] 
				indexes.get() 
				s.remove(val) 
				s.add(pages[i]) 
				indexes.put(pages[i]) 
				page_faults += 1
	return page_faults 


def lru(pages, n, capacity): 
	s = set() 
	indexes = {} 
	page_faults = 0
	for i in range(n):  
		if len(s) < capacity:  
			if pages[i] not in s: 
				s.add(pages[i]) 
				page_faults += 1
			indexes[pages[i]] = i 
		else: 
			if pages[i] not in s: 
				lru = float('inf') 
				for page in s: 
					if indexes[page] < lru: 
						lru = indexes[page] 
						val = page 
				s.remove(val) 
				s.add(pages[i]) 
				page_faults += 1
			indexes[pages[i]] = i 
	return page_faults 

def optimal(pages,n,capacity):
    page_faults = 0
    frames = [-1] * capacity
    for i in range(n):
        if pages[i] not in frames:
            if -1 in frames:
                empty_frame_index = frames.index(-1)
                frames[empty_frame_index] = pages[i]
            else:
                farthest = i + 1
                farthest_page = frames[0]
                for j in range(len(frames)):
                    try:
                        index = pages[i+1:].index(frames[j])
                        if index > farthest:
                            farthest = index
                            farthest_page = frames[j]
                    except ValueError:
                        farthest_page = frames[j]
                        break
                frames[frames.index(farthest_page)] = pages[i]
            page_faults += 1
    return page_faults


def main():
	pages = []
	n=int(input("enter no of pages : "))
	for i in range(n):
		x=int(input("enter page : "))
		pages.append(x)
	print(pages)
	capacity=int(input("enter size of frame : "))
	while(True):
		print("MENU")
		print("1.First in First Out Page Replacement Algorithm")
		print("2.Least Recently Used Page Replacement Algorithm")
		print("3.Optimal Page Replacement Algorithm")
		ch=int(input("Enter your choice"))
		if(ch==1):
			print("Page faults : ",fifo(pages, n, capacity))
			print("Page hits : ",n-fifo(pages, n, capacity))
		elif(ch==2):
			print("Page faults : ",lru(pages, n, capacity))
			print("Page hits : ",n-lru(pages, n, capacity))
		elif(ch==3):
			print("Page faults : ",optimal(pages, n, capacity))
			print("Page hits : ",n-optimal(pages, n, capacity))

main()

