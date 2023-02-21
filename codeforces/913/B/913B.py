n=int(input())
tree=[{"parent":None,
       "children":[],
       "value":1,
       "leaf":False}]

def add_node(tree,node):
    for i in range(len(tree)):
        if tree[i]["value"]==node["parent"]:
            tree[i]["children"].append(node)
            tree[i]["leaf"]=False
            return tree
        else:
            add_node(tree[i]["children"],node)
    return tree



for i in range(n-1):
    parent = int(input())
    node = {
        'parent': parent,
        'children': [],
        'value': i+2,
        'leaf': True
    }
    tree = add_node(tree, node)

def is_spruce(tree):
    for i in range(len(tree)):
        if tree[i]["leaf"]==False:
            if len(tree[i]["children"])>=3:
                leaf_count = 0
                for j in range(len(tree[i]["children"])):
                    if tree[i]["children"][j]["leaf"]==True:
                        leaf_count+=1
                if leaf_count<3:
                    return False
            else:
                return False
        if is_spruce(tree[i]["children"])==False:
            return False
    return True
                
                    

if is_spruce(tree):
    print("Yes")
else:
    print("No")