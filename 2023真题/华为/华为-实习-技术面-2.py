
class decisionTree:
    def __init__(self, max_depth = None):
        self.max_depth = max_depth

    def fit(self, x, y, depth = 0):
        self.tree = self._build_tree(x,y)
    
    def _build_tree(self, x, y, depth = 0):
        # 判断深度及终止条件
        if self.max_depth is not None and depth >= self.max_depth:
            return {'label': set(y)}

        # 选择特征，计算最佳特征
        feature, value = self._select_feature(x, y)
        # 创建当前节点
        node = {
            "feature": feature,
            "value": value,
            "left": None,
            "right": None
        }
        # 根据特征划分数据
        left_x, left_y, right_x, right_y = self._split_dataset(x, y, feature, value)

        # 递归构建左树和右树
        node["left"] = self._build_tree(left_x, left_y, depth=depth+1)
        node["right"] = self._build_tree(right_x, right_y, depth=depth+1)

        return node

    def _split_dataset(x, y, feature, value):
        pass

    def _select_feature(x, y):
        pass